#include "pch.h"
#include "Link.h"

//����������� � ������ ������������� ����������.
Link::Link(Image * l_ptr, int l_id, int l_str, Id_string * r_ptr, int r_id, int r_str): left_ptr(l_ptr), left_id(l_id), left_strength(l_str),
		right_ptr(r_ptr), right_id(r_id), right_strength(r_str)
{
	//���������� �������� � ��������� ����.
	++counter;
	id = counter;

	//������ ���� � ������� ��������.
	const time_t timer = time(0);
	ctime_s(time_date, 26, &timer);
}

//���������� ����� � ����� ��������.
inline void Link::set_left_obj(Image * l_ptr, int l_id, int l_str)
{
	left_ptr = l_ptr;
	left_id = l_id;
	left_strength = l_str;
}

//���������� ����� � ������ ��������.
inline void Link::set_right_obj(Id_string * r_ptr, int r_id, int r_str)
{
	right_ptr = r_ptr;
	right_id = r_id;
	right_strength = r_str;
}

//���������������� ���������� � ���� � ������� ��������.
inline void Link::Time_date()
{
	const time_t timer = time(0);
	ctime_s(time_date, 26, &timer);
}


//����� ������� ��-�����.

//�������� ����� � �������� ����.
bool Links::bin_write(ofstream & fout, const Link & link)
{
	int id = link.get_id();
	fout.write((char*)&id, sizeof(id));

	const string time_date = link.get_time_date();
	fout.write(time_date.c_str(), 26);

	id = link.get_left_id();
	fout.write((char*)&id, sizeof(id));

	int strength = link.get_left_strength();
	fout.write((char*)&strength, sizeof(strength));

	id = link.get_right_id();
	fout.write((char*)&id, sizeof(id));

	strength = link.get_right_strength();
	fout.write((char*)&strength, sizeof(strength));

	if (fout)//��� ��� ������� ��������, ���������� true.
	{
		return true;
	}
	else
	{
		return false;
	}
}
