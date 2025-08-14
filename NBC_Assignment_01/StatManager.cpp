#include "StatManager.h"
#include <iostream>

int main()
{
	StatManager* SM = new StatManager;

	SM->InputStat();
	SM->SetPotion(5, &SM->HPPotion, &SM->MPPotion);
	SM->ShowOptions();
	SM->SelectOption();

	return 0;
}

StatManager::StatManager()
{
}

void StatManager::InputStat()
{
	// HP와 MP 입력
	while (!input1)
	{
		std::cout << "HP와 MP를 입력해주세요: ";
		std::cin >> input1 >> input2;
		if (input1 <= 50 || input2 <= 50)
		{
			std::cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요." << std::endl;
			input1 = 0;
		}
	}
	status[0] = input1;
	status[1] = input2;

	// 공격력과 방어력 입력
	input1 = 0;
	while (!input1)
	{
		std::cout << "공격력과 방어력을 입력해주세요: ";
		std::cin >> input1 >> input2;
		if (input1 <= 0 || input2 <= 0)
		{
			std::cout << "공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요." << std::endl;
			input1 = 0;
		}
	}
	status[2] = input1;
	status[3] = input2;

	return;
}

void StatManager::SetPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	if (p_HPPotion)
	{
		*p_HPPotion = count;
	}
	if (p_MPPotion)
	{
		*p_MPPotion = count;
	}
	std::cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 " << count << "개)" << std::endl;
}

void StatManager::ShowOptions()
{
	std::cout << "=============================================" << std::endl;
	std::cout << "<스탯 관리 시스템>" << std::endl;
	std::cout << "1. HP 회복" << std::endl;
	std::cout << "2. MP 회복" << std::endl;
	std::cout << "3. HP 강화" << std::endl;
	std::cout << "4. MP 강화" << std::endl;
	std::cout << "5. 공격 스킬 사용" << std::endl;
	std::cout << "6. 필살기 사용" << std::endl;
	std::cout << "7. 나가기" << std::endl;
}

void StatManager::SelectOption()
{
	int OptionNumber = 0;

	while (OptionNumber != 7)
	{
		std::cout << "번호를 선택해주세요: ";
		std::cin >> OptionNumber;

		switch (OptionNumber)
		{
		case 1:
			HealHP();
			break;
		case 2:
			HealMP();
			break;
		case 3:
			ReinforceHP();
			break;
		case 4:
			ReinforceMP();
			break;
		case 5:
			AttackSkill();
			break;
		case 6:
			UltimateSkill();
			break;
		case 7:
			QuitGame();
			break;
		default:
			break;
		}
	}
	
}

void StatManager::HealHP()
{
	if (HPPotion)
	{
		SetStatus(0, 20);
		HPPotion--;
		std::cout << "* HP가 20 회복되었습니다. 포션이 1개 차감됩니다." << std::endl;
		ShowHP();
		std::cout << "남은 포션 수: " << HPPotion << std::endl;
	}
	else 
	{
		std::cout << "포션이 부족합니다." << std::endl;
	}
}

void StatManager::HealMP()
{
	if (MPPotion)
	{
		SetStatus(1, 20);
		MPPotion--;
		std::cout << "* MP가 20 회복되었습니다. 포션이 1개 차감됩니다." << std::endl;
		ShowMP();
		std::cout << "남은 포션 수: " << MPPotion << std::endl;
	}
	else
	{
		std::cout << "포션이 부족합니다." << std::endl;
	}
}

void StatManager::ReinforceHP()
{
	SetStatus(0, status[0]);
	std::cout << "* HP가 2배로 증가되었습니다." << std::endl;
	ShowHP();
}

void StatManager::ReinforceMP()
{
	SetStatus(1, status[1]);
	std::cout << "* MP가 2배로 증가되었습니다." << std::endl;
	ShowMP();
}

void StatManager::AttackSkill()
{
	if (status[1] < 50)
	{
		std::cout << "스킬 사용이 불가합니다." << std::endl;
	}
	else
	{
		SetStatus(1, -50);
		std::cout << "* 스킬을 사용하여 MP가 50 소모되었습니다." << std::endl;
		ShowMP();
	}
}

void StatManager::UltimateSkill()
{
	SetStatus(1, -status[1]/2);
	std::cout << "* 스킬을 사용하여 MP가 50% 소모되었습니다." << std::endl;
	ShowMP();
}

void StatManager::QuitGame()
{
	std::cout << "프로그램을 종료합니다." << std::endl;
}

void StatManager::SetStatus(int inType, int inDiff)
{
	status[inType] += inDiff;
}

void StatManager::ShowHP()
{
	std::cout << "현재 HP: " << status[0] << std::endl;
}

void StatManager::ShowMP()
{
	std::cout << "현재 MP: " << status[1] << std::endl;
}
