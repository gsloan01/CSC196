#pragma once
#include "Object/Actor.h"


class Enemy : public nc::Actor
{
public:
	void SetTarget(Actor* actor) { m_target = actor; }
	virtual bool Load(const std::string& filename) override;
	virtual void Update(float dt) override;
	virtual void Draw(Core::Graphics& graphics) override;
private:
	nc::Vector2 velocity;
	float m_thrust;
	Actor* m_target = nullptr;
};