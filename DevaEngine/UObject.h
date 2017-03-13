#ifndef _UOBJECT_H
#define _UOBJECT_H

//Additional incliudes
#ifndef _CONTEXT_H
	#include "context.h"
#endif // !_CONTEXT_H
#ifndef _STRING_H
	#include "string.h"
#endif // !_STRING_H


class UObject
{
public:
	UObject();
	UObject(const std::tstring& name);
	virtual ~UObject();
	/*
	void* operator new(size_t size);
	void operator delete(void* pdelete);
	*/
	virtual bool Initialize()						{ m_bInitialized = true; return true; }
	virtual bool PostInitialize()					{ m_bPostInitialized = true; return true; }
	virtual bool LoadContent()						{ m_bContentLoaded = true; return true; }
	virtual bool PostLoadContent()					{ m_bPostContentLoaded = true; return true; }
	virtual bool Update(Context& context)			{ return true; }
	//virtual bool LateUpdate(Context& context)		{ return true; }
	virtual bool Draw(Context& context)				{ return true; }
	virtual bool DrawUI(Context& context)			{ return true; }
	virtual bool ShutDown()							{ return true; }

	virtual void Reset();

	void SetName(const std::tstring& name) { m_Name = name; }
	const std::tstring& GetName() { return m_Name; }

	bool Initialized() const { return m_bInitialized; }
	bool PostInitialized() const { return m_bPostInitialized; }
	bool ContentLoaded() const { return m_bContentLoaded; }
	bool PostContentLoaded() const { return m_bPostContentLoaded; }

	void SetCanTick(bool canTick) { m_bCanTick = canTick; }
	bool CanTick() const { return m_bCanTick; }
	void SetCanDraw(bool canDraw) { m_bCanDraw = canDraw; }
	bool CanDraw() const { return m_bCanDraw; }

	void Destroy() { m_bDestroyed = true; }
	bool Destroyed() { return m_bDestroyed; }

	void Activate() { m_bActivated = true; }
	void DeActivate() { m_bActivated = false; }
	bool Activated() { return m_bActivated; }

protected:

	static int m_objectAmount;
	int m_ID;

	bool m_bInitialized;
	bool m_bPostInitialized;

	bool m_bContentLoaded;
	bool m_bPostContentLoaded;

	std::tstring m_Name;

private:
	bool m_bActivated;
	bool m_bDestroyed;

	bool m_bCanTick;
	bool m_bCanDraw;
};

#endif // !_UOBJECT_H