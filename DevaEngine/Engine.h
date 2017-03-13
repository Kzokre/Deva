#ifndef _ENGINE_H
#define _ENGINE_H

//C Runtime Header Files
#ifndef _WINDOWS_
	#include <Windows.h>
#endif // !_WINDOWS_
#ifndef _MAP_
	#include <map>
#endif // !_MAP_
#ifndef _CONTEXT_H
	#include "context.h"
#endif // !_CONTEXT_H

//Állapotok
enum EngineState
{
	Invalid,
	Constucting,
	Initializing,
	Running,
	ShuttingDown,
	Destroying
};

//Kijelentések
enum SystemType;
class System;
class Game;

class Engine
{
public:
	Engine();
	~Engine();
	
	int RunLoop();
	/*
	void* operator new(size_t size);
	void operator delete(void* pdelete);
	*/
	static EngineState GetEngineState() { return m_EngineState; }
private:

	int Initialize();
	int Draw(const Context& context);
	int Update(const Context& context);
	int ShutDown();

	//Add coresys to game engine
	int AddSystem(System* psys);
	//Retrieve coresys from engine
	template<typename T>
	T* GetSystem(SystemType systype)
	{
		T* psys = static_cast<T*>(m_mapSystems[systype]);
		if (!psys)
		{
			//Logger::Log("System is not valid");
			return nullptr;
		}
		return psys;
	}

	//Create Game Instance
	Game* CreateGame();
	std::map<SystemType, System*> m_mapSystems;

	static EngineState m_EngineState;
};

#endif // !_ENGINE_H