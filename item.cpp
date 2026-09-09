[...]

void CItem::UpdatePacket()
{
	if (!m_pOwner || !m_pOwner->GetDesc())
		return;

#ifdef ENABLE_SWITCHBOT
	if (m_bWindow == SWITCHBOT)
		return;
#endif

	[...]
}

[...]

LPITEM CItem::RemoveFromCharacter()
{
	[...]

			if (IsDragonSoul())
			{
				[...]
			}
#ifdef ENABLE_SWITCHBOT
			else if (m_bWindow == SWITCHBOT)
			{
				CSwitchbotManager::Instance().UnregisterItem(pOwner->GetPlayerID(), m_wCell);

				if (m_wCell >= SWITCHBOT_SLOT_COUNT)
				{
					sys_err("CItem::RemoveFromCharacter: pos >= SWITCHBOT_SLOT_COUNT");
				}
				else
				{
					pOwner->SetItem(TItemPos(SWITCHBOT, m_wCell), NULL);
				}
			}
#endif
			else
			{
				[...]
			}
	[...]
}

[...]

bool CItem::AddToCharacter(LPCHARACTER ch, TItemPos Cell)
{
	[...]

	if (INVENTORY == window_type)
	{
		[...]
	}
	else if (DRAGON_SOUL_INVENTORY == window_type)
	{
		[...]
	}
#ifdef ENABLE_SWITCHBOT
	else if (SWITCHBOT == window_type)
	{
		if (m_wCell >= SWITCHBOT_SLOT_COUNT)
		{
			sys_err("CItem::AddToCharacter:switchbot cell overflow: %s to %s cell %d", m_pProto->szName, ch->GetName(), m_wCell);
			return false;
		}
	}
#endif

	[...]
}
