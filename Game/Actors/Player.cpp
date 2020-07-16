#include "Player.h"
#include "Math/Math.h"


bool Player::Load(const std::string& filename)
{
	bool success = false;

	std::ifstream stream(filename);
	if (stream.is_open())
	{
		success = true;

		// load the base actor members
		Actor::Load(stream);

		// stream into thrust
		stream >> m_thrust;

		// stream into rotation rate
		stream >> m_rotation;

		stream.close();
	}

	return success;

}

void Player::Update(float dt)
{
	nc::Vector2 force;
	if (Core::Input::IsPressed('W')) { force = nc::Vector2::forward * m_thrust; }
	force = nc::Vector2::Rotate(force, m_transform.angle);

	//GRAVITY
	//force = force + nc::Vector2{ 0,200 };

	m_velocity += (force * dt);
	m_velocity *= .99;

	m_transform.position += (m_velocity * dt);

	if (Core::Input::IsPressed('A')) m_transform.angle -= (nc::DegreesToRadians(m_rotation) * dt);
	if (Core::Input::IsPressed('D')) m_transform.angle += (nc::DegreesToRadians(m_rotation) * dt);

	if (m_transform.position.x > 800) m_transform.position.x = 0;
	if (m_transform.position.x < 0)   m_transform.position.x = 800;
	if (m_transform.position.y > 600) m_transform.position.y = 0;
	if (m_transform.position.y < 0)   m_transform.position.y = 600;

	m_transform.Update();
}

void Player::Draw(Core::Graphics& graphics)
{
	Actor::Draw(graphics);
}
