//Just for demo purpose
class CHNConfigManager// : public fiTimerPerformer
{
  public:
  	CHNConfigManager();
  	virtual ~CHNConfigManager();

	/////////////////////////////////////////////////////////////////////////////////
	// Volume:
	/////////////////////////////////////////////////////////////////////////////////
	FI_INT GetVolumeValue();
	FI_VOID TurnUpVolume();
	FI_VOID TurnDownVolume();
	FI_INT GetVolumeLevelCount();
	FI_VOID SetVolumeLevelAt(FI_INT nIndex);
	FI_VOID SetVolumeMute(FI_BOOL bOn);
	FI_BOOL IsVolumeMuteOn();
  protected:
  private:
	CConfigManager *m_pConfigManager;
};
