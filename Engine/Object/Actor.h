#pragma once
#include <string>
#include "Math/Transform.h"
#include "Math/Shape.h"

namespace nc 
{
	class Actor
	{
	public:
		Actor() {};
		Actor(const Transform& transform, const Shape& shape) : m_transform{ transform }, m_shape{ shape }{};
		virtual ~Actor() {};

		virtual bool Load(const std::string& filename);
		virtual void Load(std::istream& stream);
		virtual void Update(float dt);
		virtual void Draw(Core::Graphics& graphics);

		Transform& GetTransform() { return m_transform; }; // return the transform
		Shape& GetShape() { return m_shape; };// return the shape

	protected:
		Transform m_transform;
		Shape m_shape;
	};
}
