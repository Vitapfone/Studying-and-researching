﻿#include "pch.h"
#include "Figures.h"



// CIRCLE //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Унаследованная функция отрисовки.
void Circle::print(Frame & ws) const
{
	
	for (int y = where().y_; y <= where().y_ + 2 * radius_; ++y)
	{
		for (int x = where().x_; x <= where().x_ + 2 * radius_; ++x)
		{
			if (x >= 0 && x < ws[0].size() && y >= 0 && y < ws.size())
			{
				if ((x - (where().x_ + radius_))*(x - (where().x_ + radius_)) + (y - (where().y_ + radius_))*(y - (where().y_ + radius_)) <= radius_ * radius_)
				{
					ws[y][x] = '0';
				}
			}
		}
	}
}


// RECTANGLE ////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Функция отрисовки прямоугольника, унаследованная от предка.
void My::Rectangle::print(Frame & ws) const
{
	for (int y = where().y_; y < (where().y_ + a_); ++y) //Функция отрисовывает квадрат, перебирая по очереди содержимое рядов.
	{
		for (int x = where().x_; x < (where().x_ + 1.6*a_); ++x)//Внутренний цикл печатает символы ряда. Большая сторона  увеличена в 1.6 раза.
		{
			if (x >= 0 && x < ws[0].size() && y >= 0 && y < ws.size())//Условие, предостерегающее от выхода за границы массива.
			{
				ws[y][x] = '0';
			}
		}
	}
}


// RHOMB ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Определение унаследованной виртуальной функции.
void Rhomb::print(Frame & ws) const
{
	for (int y = where().y_; y <= (where().y_ + diagonal_ / 2); ++y)
	{
		for (int x = where().x_; x <= (where().x_ + diagonal_); ++x)
		{
			if (x >= 0 && x < ws[0].size() && y >= 0 && y < ws.size())//Условие, предохраняющее от выхода за границы массива.
			{
				if (x >= ((where().x_ + diagonal_ / 2) - (y - where().y_)) && x <= (where().x_ + diagonal_ / 2) + (y - where().y_))
				{
					ws[y][x] = '0';
				}
			}
		}
	}


	if (diagonal_ % 2 != 0)//Случай нечетной длины диагонали. Нужно в связи с ограничениями растрового представления.
	{
		for (int y = where().y_ + diagonal_ / 2 - 1; y <= (where().y_ + diagonal_ - 1); ++y)
		{
			for (int x = where().x_ + 1; x < (where().x_ + diagonal_ - 1); ++x)
			{
				if (x >= 0 && x < ws[0].size() && y >= 0 && y < ws.size())//Условие, предохраняющее от выхода за границы массива.
				{
					if (x - 1 >= ((where().x_ + diagonal_ / 2) - (where().y_ + diagonal_ - y)) && x + 1 <= ((where().x_ + diagonal_ / 2) + (where().y_ + diagonal_ - y)))
					{
						ws[y][x] = '0';
					}
				}
			}
		}
		return;
	}


	for (int y = where().y_ + diagonal_ / 2; y <= (where().y_ + diagonal_); ++y)//Для четной длины диагонали.
	{
		for (int x = where().x_; x < (where().x_ + diagonal_); ++x)
		{
			if (x >= 0 && x < ws[0].size() && y >= 0 && y < ws.size())//Условие, предохраняющее от выхода за границы массива.
			{
				if (x >= ((where().x_ + diagonal_ / 2) - (where().y_ + diagonal_ - y)) && x <= ((where().x_ + diagonal_ / 2) + (where().y_ + diagonal_ - y)))
				{
					ws[y][x] = '0';
				}
			}
		}
	}
}


// SQUARE ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Функция отрисовки квадрата, унаследованная от предка.
void Square::print(Frame & ws) const
{

	for (int y = where().y_; y != (where().y_ + a_); ++y) //Функция отрисовывает квадрат, перебирая по очереди содержимое рядов.
	{
		for (int x = where().x_; x != (where().x_ + a_); ++x)//Внутренний цикл печатает символы ряда
		{
			if (x >= 0 && x < ws[0].size() && y >= 0 && y < ws.size())//Условие, предостерегающее от выхода за границы массива.
			{
				ws[y][x] = '0';
			}
		}
	}
}


// TRIANGLE ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Унаследованная функция отрисовки треугольника.
void Triangle::print(Frame & ws) const
{
	for (int y = where().y_; y <= point_A_.y_; ++y)
	{
		for (int x = where().x_; x <= point_B_.x_; ++x)
		{
			if (x >= 0 && x < ws[0].size() && y >= 0 && y < ws.size())//Условие, предохраняющее от выхода за границы массива.
			{
				if (x - where().x_ < y - where().y_)
				{
					ws[y][x] = '0';
				}
			}
		}
	}
}
