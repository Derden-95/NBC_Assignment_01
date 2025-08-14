#pragma once

class StatManager
{
public:
	StatManager();
	void InputStat();
	void SetPotion(int count, int* p_HPPotion, int* p_MPPotion);
	void ShowOptions();
	void SelectOption();

	void HealHP();
	void HealMP();
	void ReinforceHP();
	void ReinforceMP();
	void AttackSkill();
	void UltimateSkill();
	void QuitGame();

private:
	void SetStatus(int inType, int inDiff);
	void ShowHP();
	void ShowMP();

public:
	int HPPotion = 0;
	int MPPotion = 0;

private:
	int input1 = 0;
	int input2 = 0;

	int status[4] = { 0 }; // HP, MP, ATK, DEF

};