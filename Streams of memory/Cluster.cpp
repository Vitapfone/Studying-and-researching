#include "pch.h"
#include "Cluster.h"

//������� �������� �� ���� ��������.
void Cluster::counter(const Inner_frame & ws, char background)
{
	for (size_t y = loc_.y_; y != (loc_.y_ + s_); ++y)//���������� ��� ��-�� �������� ������������ � �������� ����������� ��������.
	{
		for (size_t x = loc_.x_; x != (loc_.x_ + s_); ++x)
		{
			if (x >= 0 && x < ws[0].size() && y >= 0 && y < ws.size())//�������, ���������������� �� ������ �� ������� �������.
			{
				if (ws[y][x] != background)//���� ��-� �� ����� ����,
				{
					++count_;//�� ����������� ������� ����� ��-���.
				}
			}
		}
	}
}
