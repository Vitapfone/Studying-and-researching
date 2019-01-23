#include "pch.h"
#include "Figure.h"
#include "Square.h"

//������� ��������� ��������, �������������� �� ������.
void Square::print(Ar60_30 & ws)
{

	for (int y = y0; y != (y0 + a); ++y) //������� ������������ �������, ��������� �� ������� ���������� �����.
	{
		for (int x = x0; x != (x0 + a); ++x)//���������� ���� �������� ������� ����
		{
			if (x >= 0 && x < 60 && y >= 0 && y < 30)//�������, ���������������� �� ������ �� ������� �������.
			{
				ws[y][x] = '0';
			}
		}
	}
}






