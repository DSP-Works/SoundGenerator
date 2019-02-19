/*
* @author PELLETIER Benoit
*
* @file MultiplyComponent.cpp
*
* @date 18/02/2019
*
* @brief Define a component that multiply tow signals
*
*/

#include "stdafx.h"
#include "MultiplyComponent.h"

MultiplyComponent::MultiplyComponent()
{
	m_name = "Multiply";

	m_inputs.push_back(ComponentInput("Signal A", this));
	m_inputs.push_back(ComponentInput("Signal B", this));

	m_inputs[0].setDefaultValue(0.0f);
	m_inputs[1].setDefaultValue(0.0f);
}

MultiplyComponent::~MultiplyComponent()
{
}

float MultiplyComponent::getOutput(float _time)
{
	float signalA = m_inputs[0].getValue(_time);
	float signalB = m_inputs[1].getValue(_time);
	return signalA * signalB;
}
