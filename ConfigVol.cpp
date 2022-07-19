//Just for demo purpose

FI_INT CHNConfigManager::GetVolumeValue()
{
	return m_pConfigManager->GetVolumeValue();
}

FI_VOID CHNConfigManager::TurnUpVolume()
{
	m_pConfigManager->TurnUpVolume();
}

FI_VOID CHNConfigManager::TurnDownVolume()
{
	m_pConfigManager->TurnDownVolume();
}

FI_INT CHNConfigManager::GetVolumeLevelCount()
{
	return m_pConfigManager->GetVolumeLevelCount();
}

FI_VOID CHNConfigManager::SetVolumeLevelAt(FI_INT nIndex)
{
	m_pConfigManager->SetVolumeLevelAt(nIndex);
}

FI_VOID CHNConfigManager::SetVolumeMute(FI_BOOL bOn)
{
	m_pConfigManager->SetVolumeMute(bOn);
}

FI_BOOL CHNConfigManager::IsVolumeMuteOn()
{
	return m_pConfigManager->IsVolumeMuteOn();
}
