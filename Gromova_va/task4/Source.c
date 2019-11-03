﻿#include <stdio.h> 
#include <locale.h> 
#include <time.h> 
#include <stdlib.h> 
int main()
{
 setlocale(2, "Russian");
 srand(time(NULL));
 int n, i, m,t = 0;
 int sh[7] = { 1234, 5673, 3739, 9874, 5231, 4780,2984 }; // штрихкоды
 char tov[7][19] = { {"Масло сливочное"}, {"Сыр"}, {"Творог"}, {"Кефир"}, {"Ряженка"}, {"Сливки"}, {"Молоко"} };
 int price[7] = { 180, 520, 220, 60, 100, 300, 50 }; // цена за единицу продукта(кг/литр)
 int quantity[7] = { 0 };
 int absolute[7] = { 0 };//цена со скидкой
 int sale[7] = { 0 }; //скидка для товара
 int SALE = 0; // суммарная скидка 
 int sum = 0; // сумммарная стоимость всех покупок
 printf_s("Добро пожаловать в магазин молочных продуктов.\n Введите номер штрихкода из существующих:\n 1234\n 5673\n 3739\n 9874\n 5231\n 4780\n 2984\n Введите 0, чтобы закончить и сформировать чек.\n");
 scanf_s("%d", &n);
 for (i = 0; i < 7; i++)
 {
  sale[i] = (rand() % 50) + 5;
 }
 while (n != 0)
 {
  while ((n != sh[0]) && (n != 0) && (n != sh[1]) && (n != sh[2]) && (n != sh[3]) && (n != sh[4]) && (n != sh[5]) && (n != sh[6]) && (n != sh[7]))
  {
   printf("Товара с таким штрихкодом нет.Введите штрихкод заново:\n");
   scanf_s("%d", &n);
  }
  for (i = 0; i < 7; i++)
  {
    if (n == 0)
	 break;
	else
	 if (n == sh[i])
	 {
	  printf("Ваш товар: ");
	  puts(tov[i]);
	  absolute[i] = price[i] * (100 - sale[i]) / 100;
	  printf("Цена %d руб.\nСкидка на товар %d проц.\nЦена на товар с учетом скидки %d руб.\n", price[i], sale[i], absolute[i]);
	  printf("Введите количество покупаемого товара: \n");
	  scanf_s("%d", &m);
	  quantity[i] += m;
	  printf("Введите штрихкод следующего товара или если вы хотите завершить ,то введите 0.\n");
	  scanf_s("%d", &n);
	  break;
	 }
  }
 }
 for (i = 0; i < 7; i++)
 {
  absolute[i] = quantity[i] * (price[i] * (100 - sale[i]) / 100);
  t = t + (quantity[i] * price[i]);//суммарная стоимость товаров без скидки
  sum = sum + absolute[i] ;//стоимость товаров со скидкой
 }
 SALE = t - sum;
 //Формируем чек
 printf_s("\n\n");
 printf_s("КАССОВЫЙ ЧЕК\n");
 for (i = 0; i < 7; i++)
 {
  if (quantity[i] != 0)
  {
   puts(tov[i]);
   printf_s("Количество %d шт , цена с учетом количества и скидки %d \n", quantity[i], absolute[i]);
  }
 }
 printf_s("ВАША СКИДКА : %d  РУБЛЕЙ \n", SALE);
 printf_s("ИТОГО : %d РУБЛЕЙ\n", sum);
 printf_s("СПАСИБО ЗА ПОКУПКУ!\n");
 system("pause");
}