/*
 * Copyright 2019-2020 Benoit Pelletier
 *
 * This file is part of Sound Generator.
 *
 * Sound Generator is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Sound Generator is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Sound Generator.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "PinOutputItem.h"
#include "PinInputItem.h"

PinOutputItem::PinOutputItem(QGraphicsItem *parent)
    : PinItem(parent)
{
}

bool PinOutputItem::_canConnect(PinItem *_other)
{
    PinInputItem* input = qgraphicsitem_cast<PinInputItem*>(_other);
    if (input != nullptr && input->input() != nullptr && input->input()->getParent() != nullptr
        && m_component != nullptr && input->input()->getParent() != m_component
        && input->input()->canSetComponent(m_component))
    {
        return PinItem::_canConnect(_other);
    }
    return false;
}
