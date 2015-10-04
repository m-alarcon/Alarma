/*
TÃ­tulo: RTC_Alarma
VersiÃ³n: 1.0v
DescripciÃ³n: Alarma usando el reloj DS1307.
Autor: FjRamirez
Fecha: 09/07/2014
URL: www.tuelectronica.es
email: email@tuelectronica.es
*/

#include <Wire.h> 
#include "RTClib.h"
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <string.h>

LiquidCrystal_I2C	lcd(0x27, 2, 1, 0, 4, 5, 6, 7); // 0x27 is the I2C bus address for an unmodified backpack
RTC_DS1307 RTC;
DateTime future = 0; // Variable para calcular cuando se debe desactivar la alarma

// CONFIGURACIÃ“N DE USUARIO
// No se tiene en cuenta el aÃ±o, mes y dÃ­a de la alarma
// ALARMA 1
int seconds_alarm = 0; // Segundos alarma
int minutes_alarm = 17; // Minutos alarma
int hour_alarm = 20; // Horas alarma. Formato 24h
int day_alarm = 9; // Dia alarma
int month_alarm = 7; // Mes alarma
int year_alarm = 2014; // AÃ±o alarma
int weekday_alarm = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 2
int seconds_alarm2 = 10; // Segundos alarma
int minutes_alarm2 = 17; // Minutos alarma
int hour_alarm2 = 20; // Horas alarma. Formato 24h
int day_alarm2 = 9; // Dia alarma
int month_alarm2 = 7; // Mes alarma
int year_alarm2 = 2014; // AÃ±o alarma
int weekday_alarm2 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 3
int seconds_alarm3 = 20; // Segundos alarma
int minutes_alarm3 = 17; // Minutos alarma
int hour_alarm3 = 20; // Horas alarma. Formato 24h
int day_alarm3 = 9; // Dia alarma
int month_alarm3 = 7; // Mes alarma
int year_alarm3 = 2014; // AÃ±o alarma
int weekday_alarm3 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 4
int seconds_alarm4 = 30; // Segundos alarma
int minutes_alarm4 = 17; // Minutos alarma
int hour_alarm4 = 20; // Horas alarma. Formato 24h
int day_alarm4 = 9; // Dia alarma
int month_alarm4 = 7; // Mes alarma
int year_alarm4 = 2014; // AÃ±o alarma
int weekday_alarm4 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 5
int seconds_alarm5 = 40; // Segundos alarma
int minutes_alarm5 = 17; // Minutos alarma
int hour_alarm5 = 20; // Horas alarma. Formato 24h
int day_alarm5 = 9; // Dia alarma
int month_alarm5 = 7; // Mes alarma
int year_alarm5 = 2014; // AÃ±o alarma
int weekday_alarm5 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 6
int seconds_alarm6 = 40; // Segundos alarma
int minutes_alarm6 = 17; // Minutos alarma
int hour_alarm6 = 20; // Horas alarma. Formato 24h
int day_alarm6 = 9; // Dia alarma
int month_alarm6 = 7; // Mes alarma
int year_alarm6 = 2014; // AÃ±o alarma
int weekday_alarm6 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 7
int seconds_alarm7 = 40; // Segundos alarma
int minutes_alarm7 = 17; // Minutos alarma
int hour_alarm7 = 20; // Horas alarma. Formato 24h
int day_alarm7 = 9; // Dia alarma
int month_alarm7 = 7; // Mes alarma
int year_alarm7 = 2014; // AÃ±o alarma
int weekday_alarm7 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 8
int seconds_alarm8 = 40; // Segundos alarma
int minutes_alarm8 = 17; // Minutos alarma
int hour_alarm8 = 20; // Horas alarma. Formato 24h
int day_alarm8 = 9; // Dia alarma
int month_alarm8 = 7; // Mes alarma
int year_alarm8 = 2014; // AÃ±o alarma
int weekday_alarm8 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 9
int seconds_alarm9 = 40; // Segundos alarma
int minutes_alarm9 = 17; // Minutos alarma
int hour_alarm9 = 20; // Horas alarma. Formato 24h
int day_alarm9 = 9; // Dia alarma
int month_alarm9 = 7; // Mes alarma
int year_alarm9 = 2014; // AÃ±o alarma
int weekday_alarm9 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 10
int seconds_alarm10 = 40; // Segundos alarma
int minutes_alarm10 = 17; // Minutos alarma
int hour_alarm10 = 20; // Horas alarma. Formato 24h
int day_alarm10 = 9; // Dia alarma
int month_alarm10 = 7; // Mes alarma
int year_alarm10 = 2014; // AÃ±o alarma
int weekday_alarm10 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 11
int seconds_alarm11 = 40; // Segundos alarma
int minutes_alarm11 = 17; // Minutos alarma
int hour_alarm11 = 20; // Horas alarma. Formato 24h
int day_alarm11 = 9; // Dia alarma
int month_alarm11 = 7; // Mes alarma
int year_alarm11 = 2014; // AÃ±o alarma
int weekday_alarm11 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 12
int seconds_alarm12 = 40; // Segundos alarma
int minutes_alarm12 = 17; // Minutos alarma
int hour_alarm12 = 20; // Horas alarma. Formato 24h
int day_alarm12 = 9; // Dia alarma
int month_alarm12 = 7; // Mes alarma
int year_alarm12 = 2014; // AÃ±o alarma
int weekday_alarm12 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 13
int seconds_alarm13 = 40; // Segundos alarma
int minutes_alarm13 = 17; // Minutos alarma
int hour_alarm13 = 20; // Horas alarma. Formato 24h
int day_alarm13 = 9; // Dia alarma
int month_alarm13 = 7; // Mes alarma
int year_alarm13 = 2014; // AÃ±o alarma
int weekday_alarm13 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 14
int seconds_alarm14 = 40; // Segundos alarma
int minutes_alarm14 = 17; // Minutos alarma
int hour_alarm14 = 20; // Horas alarma. Formato 24h
int day_alarm14 = 9; // Dia alarma
int month_alarm14 = 7; // Mes alarma
int year_alarm14 = 2014; // AÃ±o alarma
int weekday_alarm14 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 15
int seconds_alarm15 = 40; // Segundos alarma
int minutes_alarm15 = 17; // Minutos alarma
int hour_alarm15 = 20; // Horas alarma. Formato 24h
int day_alarm15 = 9; // Dia alarma
int month_alarm15 = 7; // Mes alarma
int year_alarm15 = 2014; // AÃ±o alarma
int weekday_alarm15 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 16
int seconds_alarm16 = 40; // Segundos alarma
int minutes_alarm16 = 17; // Minutos alarma
int hour_alarm16 = 20; // Horas alarma. Formato 24h
int day_alarm16 = 9; // Dia alarma
int month_alarm16 = 7; // Mes alarma
int year_alarm16 = 2014; // AÃ±o alarma
int weekday_alarm16 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 17
int seconds_alarm17 = 40; // Segundos alarma
int minutes_alarm17 = 17; // Minutos alarma
int hour_alarm17 = 20; // Horas alarma. Formato 24h
int day_alarm17 = 9; // Dia alarma
int month_alarm17 = 7; // Mes alarma
int year_alarm17 = 2014; // AÃ±o alarma
int weekday_alarm17 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 18
int seconds_alarm18 = 40; // Segundos alarma
int minutes_alarm18 = 17; // Minutos alarma
int hour_alarm18 = 20; // Horas alarma. Formato 24h
int day_alarm18 = 9; // Dia alarma
int month_alarm18 = 7; // Mes alarma
int year_alarm18 = 2014; // AÃ±o alarma
int weekday_alarm18 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 19
int seconds_alarm19 = 40; // Segundos alarma
int minutes_alarm19 = 17; // Minutos alarma
int hour_alarm19 = 20; // Horas alarma. Formato 24h
int day_alarm19 = 9; // Dia alarma
int month_alarm19 = 7; // Mes alarma
int year_alarm19 = 2014; // AÃ±o alarma
int weekday_alarm19 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 20
int seconds_alarm20 = 40; // Segundos alarma
int minutes_alarm20 = 17; // Minutos alarma
int hour_alarm20 = 20; // Horas alarma. Formato 24h
int day_alarm20 = 9; // Dia alarma
int month_alarm20 = 7; // Mes alarma
int year_alarm20 = 2014; // AÃ±o alarma
int weekday_alarm20 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 21
int seconds_alarm21 = 40; // Segundos alarma
int minutes_alarm21 = 17; // Minutos alarma
int hour_alarm21 = 20; // Horas alarma. Formato 24h
int day_alarm21 = 9; // Dia alarma
int month_alarm21 = 7; // Mes alarma
int year_alarm21 = 2014; // AÃ±o alarma
int weekday_alarm21 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 22
int seconds_alarm22 = 40; // Segundos alarma
int minutes_alarm22 = 17; // Minutos alarma
int hour_alarm22 = 20; // Horas alarma. Formato 24h
int day_alarm22 = 9; // Dia alarma
int month_alarm22 = 7; // Mes alarma
int year_alarm22 = 2014; // AÃ±o alarma
int weekday_alarm22 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 23
int seconds_alarm23 = 40; // Segundos alarma
int minutes_alarm23 = 17; // Minutos alarma
int hour_alarm23 = 20; // Horas alarma. Formato 24h
int day_alarm23 = 9; // Dia alarma
int month_alarm23 = 7; // Mes alarma
int year_alarm23 = 2014; // AÃ±o alarma
int weekday_alarm23 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 24
int seconds_alarm24 = 40; // Segundos alarma
int minutes_alarm24 = 17; // Minutos alarma
int hour_alarm24 = 20; // Horas alarma. Formato 24h
int day_alarm24 = 9; // Dia alarma
int month_alarm24 = 7; // Mes alarma
int year_alarm24 = 2014; // AÃ±o alarma
int weekday_alarm24 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 25
int seconds_alarm25 = 40; // Segundos alarma
int minutes_alarm25 = 17; // Minutos alarma
int hour_alarm25 = 20; // Horas alarma. Formato 24h
int day_alarm25 = 9; // Dia alarma
int month_alarm25 = 7; // Mes alarma
int year_alarm25 = 2014; // AÃ±o alarma
int weekday_alarm25 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 26
int seconds_alarm26 = 40; // Segundos alarma
int minutes_alarm26 = 17; // Minutos alarma
int hour_alarm26 = 20; // Horas alarma. Formato 24h
int day_alarm26 = 9; // Dia alarma
int month_alarm26 = 7; // Mes alarma
int year_alarm26 = 2014; // AÃ±o alarma
int weekday_alarm26 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 27
int seconds_alarm27 = 40; // Segundos alarma
int minutes_alarm27 = 17; // Minutos alarma
int hour_alarm27 = 20; // Horas alarma. Formato 24h
int day_alarm27 = 9; // Dia alarma
int month_alarm27 = 7; // Mes alarma
int year_alarm27 = 2014; // AÃ±o alarma
int weekday_alarm27 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 28
int seconds_alarm28 = 40; // Segundos alarma
int minutes_alarm28 = 17; // Minutos alarma
int hour_alarm28 = 20; // Horas alarma. Formato 24h
int day_alarm28 = 9; // Dia alarma
int month_alarm28 = 7; // Mes alarma
int year_alarm28 = 2014; // AÃ±o alarma
int weekday_alarm28 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 29
int seconds_alarm29 = 40; // Segundos alarma
int minutes_alarm29 = 17; // Minutos alarma
int hour_alarm29 = 20; // Horas alarma. Formato 24h
int day_alarm29 = 9; // Dia alarma
int month_alarm29 = 7; // Mes alarma
int year_alarm29 = 2014; // AÃ±o alarma
int weekday_alarm29 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 30
int seconds_alarm30 = 40; // Segundos alarma
int minutes_alarm30 = 17; // Minutos alarma
int hour_alarm30 = 20; // Horas alarma. Formato 24h
int day_alarm30 = 9; // Dia alarma
int month_alarm30 = 7; // Mes alarma
int year_alarm30 = 2014; // AÃ±o alarma
int weekday_alarm30 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 31
int seconds_alarm31 = 40; // Segundos alarma
int minutes_alarm31 = 17; // Minutos alarma
int hour_alarm31 = 20; // Horas alarma. Formato 24h
int day_alarm31 = 9; // Dia alarma
int month_alarm31 = 7; // Mes alarma
int year_alarm31 = 2014; // AÃ±o alarma
int weekday_alarm31 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 32
int seconds_alarm32 = 40; // Segundos alarma
int minutes_alarm32 = 17; // Minutos alarma
int hour_alarm32 = 20; // Horas alarma. Formato 24h
int day_alarm32 = 9; // Dia alarma
int month_alarm32 = 7; // Mes alarma
int year_alarm32 = 2014; // AÃ±o alarma
int weekday_alarm32 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 33
int seconds_alarm33 = 40; // Segundos alarma
int minutes_alarm33 = 17; // Minutos alarma
int hour_alarm33 = 20; // Horas alarma. Formato 24h
int day_alarm33 = 9; // Dia alarma
int month_alarm33 = 7; // Mes alarma
int year_alarm33 = 2014; // AÃ±o alarma
int weekday_alarm33 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 34
int seconds_alarm34 = 40; // Segundos alarma
int minutes_alarm34 = 17; // Minutos alarma
int hour_alarm34 = 20; // Horas alarma. Formato 24h
int day_alarm34 = 9; // Dia alarma
int month_alarm34 = 7; // Mes alarma
int year_alarm34 = 2014; // AÃ±o alarma
int weekday_alarm34 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 35
int seconds_alarm35 = 40; // Segundos alarma
int minutes_alarm35 = 17; // Minutos alarma
int hour_alarm35 = 20; // Horas alarma. Formato 24h
int day_alarm35 = 9; // Dia alarma
int month_alarm35 = 7; // Mes alarma
int year_alarm35 = 2014; // AÃ±o alarma
int weekday_alarm35 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 36
int seconds_alarm36 = 40; // Segundos alarma
int minutes_alarm36 = 17; // Minutos alarma
int hour_alarm36 = 20; // Horas alarma. Formato 24h
int day_alarm36 = 9; // Dia alarma
int month_alarm36 = 7; // Mes alarma
int year_alarm36 = 2014; // AÃ±o alarma
int weekday_alarm36 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 37
int seconds_alarm37 = 40; // Segundos alarma
int minutes_alarm37 = 17; // Minutos alarma
int hour_alarm37 = 20; // Horas alarma. Formato 24h
int day_alarm37 = 9; // Dia alarma
int month_alarm37 = 7; // Mes alarma
int year_alarm37 = 2014; // AÃ±o alarma
int weekday_alarm37 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 38
int seconds_alarm38 = 40; // Segundos alarma
int minutes_alarm38 = 17; // Minutos alarma
int hour_alarm38 = 20; // Horas alarma. Formato 24h
int day_alarm38 = 9; // Dia alarma
int month_alarm38 = 7; // Mes alarma
int year_alarm38 = 2014; // AÃ±o alarma
int weekday_alarm38 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 39
int seconds_alarm39 = 40; // Segundos alarma
int minutes_alarm39 = 17; // Minutos alarma
int hour_alarm39 = 20; // Horas alarma. Formato 24h
int day_alarm39 = 9; // Dia alarma
int month_alarm39 = 7; // Mes alarma
int year_alarm39 = 2014; // AÃ±o alarma
int weekday_alarm39 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 40
int seconds_alarm40 = 40; // Segundos alarma
int minutes_alarm40 = 17; // Minutos alarma
int hour_alarm40 = 20; // Horas alarma. Formato 24h
int day_alarm40 = 9; // Dia alarma
int month_alarm40 = 7; // Mes alarma
int year_alarm40 = 2014; // AÃ±o alarma
int weekday_alarm40 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 41
int seconds_alarm41 = 40; // Segundos alarma
int minutes_alarm41 = 17; // Minutos alarma
int hour_alarm41 = 20; // Horas alarma. Formato 24h
int day_alarm41 = 9; // Dia alarma
int month_alarm41 = 7; // Mes alarma
int year_alarm41 = 2014; // AÃ±o alarma
int weekday_alarm41 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 42
int seconds_alarm42 = 40; // Segundos alarma
int minutes_alarm42 = 17; // Minutos alarma
int hour_alarm42 = 20; // Horas alarma. Formato 24h
int day_alarm42 = 9; // Dia alarma
int month_alarm42 = 7; // Mes alarma
int year_alarm42 = 2014; // AÃ±o alarma
int weekday_alarm42 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 43
int seconds_alarm43 = 40; // Segundos alarma
int minutes_alarm43 = 17; // Minutos alarma
int hour_alarm43 = 20; // Horas alarma. Formato 24h
int day_alarm43 = 9; // Dia alarma
int month_alarm43 = 7; // Mes alarma
int year_alarm43 = 2014; // AÃ±o alarma
int weekday_alarm43 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 44
int seconds_alarm44 = 40; // Segundos alarma
int minutes_alarm44 = 17; // Minutos alarma
int hour_alarm44 = 20; // Horas alarma. Formato 24h
int day_alarm44 = 9; // Dia alarma
int month_alarm44 = 7; // Mes alarma
int year_alarm44 = 2014; // AÃ±o alarma
int weekday_alarm44 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 45
int seconds_alarm45 = 40; // Segundos alarma
int minutes_alarm45 = 17; // Minutos alarma
int hour_alarm45 = 20; // Horas alarma. Formato 24h
int day_alarm45 = 9; // Dia alarma
int month_alarm45 = 7; // Mes alarma
int year_alarm45 = 2014; // AÃ±o alarma
int weekday_alarm45 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 46
int seconds_alarm46 = 40; // Segundos alarma
int minutes_alarm46 = 17; // Minutos alarma
int hour_alarm46 = 20; // Horas alarma. Formato 24h
int day_alarm46 = 9; // Dia alarma
int month_alarm46 = 7; // Mes alarma
int year_alarm46 = 2014; // AÃ±o alarma
int weekday_alarm46 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 47
int seconds_alarm47 = 40; // Segundos alarma
int minutes_alarm47 = 17; // Minutos alarma
int hour_alarm47 = 20; // Horas alarma. Formato 24h
int day_alarm47 = 9; // Dia alarma
int month_alarm47 = 7; // Mes alarma
int year_alarm47 = 2014; // AÃ±o alarma
int weekday_alarm47 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 48
int seconds_alarm48 = 40; // Segundos alarma
int minutes_alarm48 = 17; // Minutos alarma
int hour_alarm48 = 20; // Horas alarma. Formato 24h
int day_alarm48 = 9; // Dia alarma
int month_alarm48 = 7; // Mes alarma
int year_alarm48 = 2014; // AÃ±o alarma
int weekday_alarm48 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 49
int seconds_alarm49 = 40; // Segundos alarma
int minutes_alarm49 = 17; // Minutos alarma
int hour_alarm49 = 20; // Horas alarma. Formato 24h
int day_alarm49 = 9; // Dia alarma
int month_alarm49 = 7; // Mes alarma
int year_alarm49 = 2014; // AÃ±o alarma
int weekday_alarm49 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 50
int seconds_alarm50 = 40; // Segundos alarma
int minutes_alarm50 = 17; // Minutos alarma
int hour_alarm50 = 20; // Horas alarma. Formato 24h
int day_alarm50 = 9; // Dia alarma
int month_alarm50 = 7; // Mes alarma
int year_alarm50 = 2014; // AÃ±o alarma
int weekday_alarm50 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 51
int seconds_alarm51 = 40; // Segundos alarma
int minutes_alarm51 = 17; // Minutos alarma
int hour_alarm51 = 20; // Horas alarma. Formato 24h
int day_alarm51 = 9; // Dia alarma
int month_alarm51 = 7; // Mes alarma
int year_alarm51 = 2014; // AÃ±o alarma
int weekday_alarm51 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 52
int seconds_alarm52 = 40; // Segundos alarma
int minutes_alarm52 = 17; // Minutos alarma
int hour_alarm52 = 20; // Horas alarma. Formato 24h
int day_alarm52 = 9; // Dia alarma
int month_alarm52 = 7; // Mes alarma
int year_alarm52 = 2014; // AÃ±o alarma
int weekday_alarm52 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 53
int seconds_alarm53 = 40; // Segundos alarma
int minutes_alarm53 = 17; // Minutos alarma
int hour_alarm53 = 20; // Horas alarma. Formato 24h
int day_alarm53 = 9; // Dia alarma
int month_alarm53 = 7; // Mes alarma
int year_alarm53 = 2014; // AÃ±o alarma
int weekday_alarm53 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 54
int seconds_alarm54 = 40; // Segundos alarma
int minutes_alarm54 = 17; // Minutos alarma
int hour_alarm54 = 20; // Horas alarma. Formato 24h
int day_alarm54 = 9; // Dia alarma
int month_alarm54 = 7; // Mes alarma
int year_alarm54 = 2014; // AÃ±o alarma
int weekday_alarm54 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 55
int seconds_alarm55 = 40; // Segundos alarma
int minutes_alarm55 = 17; // Minutos alarma
int hour_alarm55 = 20; // Horas alarma. Formato 24h
int day_alarm55 = 9; // Dia alarma
int month_alarm55 = 7; // Mes alarma
int year_alarm55 = 2014; // AÃ±o alarma
int weekday_alarm55 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 56
int seconds_alarm56 = 40; // Segundos alarma
int minutes_alarm56 = 17; // Minutos alarma
int hour_alarm56 = 20; // Horas alarma. Formato 24h
int day_alarm56 = 9; // Dia alarma
int month_alarm56 = 7; // Mes alarma
int year_alarm56 = 2014; // AÃ±o alarma
int weekday_alarm56 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 57
int seconds_alarm57 = 40; // Segundos alarma
int minutes_alarm57 = 17; // Minutos alarma
int hour_alarm57 = 20; // Horas alarma. Formato 24h
int day_alarm57 = 9; // Dia alarma
int month_alarm57 = 7; // Mes alarma
int year_alarm57 = 2014; // AÃ±o alarma
int weekday_alarm57 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 58
int seconds_alarm58 = 40; // Segundos alarma
int minutes_alarm58 = 17; // Minutos alarma
int hour_alarm58 = 20; // Horas alarma. Formato 24h
int day_alarm58 = 9; // Dia alarma
int month_alarm58 = 7; // Mes alarma
int year_alarm58 = 2014; // AÃ±o alarma
int weekday_alarm58 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 59
int seconds_alarm59 = 40; // Segundos alarma
int minutes_alarm59 = 17; // Minutos alarma
int hour_alarm59 = 20; // Horas alarma. Formato 24h
int day_alarm59 = 9; // Dia alarma
int month_alarm59 = 7; // Mes alarma
int year_alarm59 = 2014; // AÃ±o alarma
int weekday_alarm59 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 60
int seconds_alarm60 = 40; // Segundos alarma
int minutes_alarm60 = 17; // Minutos alarma
int hour_alarm60 = 20; // Horas alarma. Formato 24h
int day_alarm60 = 9; // Dia alarma
int month_alarm60 = 7; // Mes alarma
int year_alarm60 = 2014; // AÃ±o alarma
int weekday_alarm60 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 61
int seconds_alarm61 = 40; // Segundos alarma
int minutes_alarm61 = 17; // Minutos alarma
int hour_alarm61 = 20; // Horas alarma. Formato 24h
int day_alarm61 = 9; // Dia alarma
int month_alarm61 = 7; // Mes alarma
int year_alarm61 = 2014; // AÃ±o alarma
int weekday_alarm61 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 62
int seconds_alarm62 = 40; // Segundos alarma
int minutes_alarm62 = 17; // Minutos alarma
int hour_alarm62 = 20; // Horas alarma. Formato 24h
int day_alarm62 = 9; // Dia alarma
int month_alarm62 = 7; // Mes alarma
int year_alarm62 = 2014; // AÃ±o alarma
int weekday_alarm62 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

// ALARMA 63
int seconds_alarm63 = 40; // Segundos alarma
int minutes_alarm63 = 17; // Minutos alarma
int hour_alarm63 = 20; // Horas alarma. Formato 24h
int day_alarm63 = 9; // Dia alarma
int month_alarm63 = 7; // Mes alarma
int year_alarm63 = 2014; // AÃ±o alarma
int weekday_alarm63 = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)

boolean all_seconds = false; // Alarma para todos los segundos
boolean all_minutes = false; // Alarma para todos los minutos
boolean all_hour = false; // Alarma para todas las horas
boolean all_weekday = false; // Alarma para todos los dias de la semana
boolean all_day = true; // Alarma para todos los dias
boolean all_month = true; // Alarma para todos los meses
boolean all_year = true; // Alarma para todos los aÃ±os
int alarm_duration = 2; // Tiempo activo de la alarma. Debe ser menor que la prÃ³xima alarma.
// FIN DEFINICIONES DE ALARMAS

int LedPin = 12; // Pin al que está conectada la bobina del relé
const int botonMenuPin = 2;
const int botonCancelPin = 3;
const int botonEnterPin = 4;
int menu = 0;


void setup () {
Wire.begin(); // Inicia el puerto I2C
RTC.begin(); // Inicia la comunicaciÃ³n con el RTC
char mes[] = "Feb";
char dia[] = "09";
char anno[] = "2015";
char sp[] = " ";
char fecha[11] = {0};
strcat(fecha, mes);
strcat(fecha, sp);
strcat(fecha, dia);
strcat(fecha, sp);
strcat(fecha, anno);
//RTC.adjust(DateTime(__DATE__, __TIME__)); // Establece la fecha y hora (Comentar una vez establecida la hora)
pinMode(LedPin, OUTPUT);  // Establece el pin LedPin como salida
pinMode(botonMenuPin, INPUT);
pinMode(botonCancelPin, INPUT);
pinMode(botonEnterPin, INPUT);
// activate LCD module
lcd.begin (16, 2); // for 16 x 2 LCD module
lcd.setBacklightPin(3, POSITIVE);
lcd.setBacklight(HIGH);
lcd.home(); // set cursor to 0,0
lcd.print("Hora actual:");
Serial.begin(9600); // Establece la velocidad de datos del puerto serie
}

void loop(){
DateTime now = RTC.now(); // Obtiene la fecha y hora del RTC

if(menu == 0){
  lcd.home();
  lcd.print("Hora actual:");
  lcd.setCursor(0,1);
  if(now.hour() < 10){
    lcd.print("0");
    lcd.print(now.hour(),1);
  } else {
    lcd.print(now.hour(),1);
  }
  lcd.print(":");
  if(now.minute() < 10){
    lcd.print("0");
    lcd.print(now.minute(),1);
  } else {
    lcd.print(now.minute(),1);
  }
  lcd.print(":");
  if(now.second() < 10){
    lcd.print("0");
    lcd.print(now.second(),1);
  } else {    
    lcd.print(now.second(),1);
  }
  Serial.print(now.year(), DEC); // AÃ±o
  Serial.print('/');
  Serial.print(now.month(), DEC); // Mes
  Serial.print('/');
  Serial.print(now.day(), DEC); // Dia
  Serial.print(' ');
  Serial.print(now.dayOfWeek(), DEC); // Dia de la semana
  Serial.print(' ');
  Serial.print(now.hour(), DEC); // Horas
  Serial.print(':');
  Serial.print(now.minute(), DEC); // Minutos
  Serial.print(':');
  Serial.print(now.second(), DEC); // Segundos
  Serial.println();
}

if (year_alarm == now.year() || all_year) {
  if (month_alarm == now.month() || all_month) {
    if (day_alarm == now.day() || all_day) {
      if (weekday_alarm == now.dayOfWeek() || all_weekday){
        if (hour_alarm == now.hour() || hour_alarm2 == now.hour() || hour_alarm3 == now.hour() || hour_alarm4 == now.hour() || hour_alarm5 == now.hour() || all_hour) {
          if (minutes_alarm == now.minute() || minutes_alarm2 == now.minute() || minutes_alarm3 == now.minute() || minutes_alarm4 == now.minute() || minutes_alarm5 == now.minute() || all_minutes) {
            if (seconds_alarm == now.second() || seconds_alarm2 == now.second() || seconds_alarm3 == now.second() || seconds_alarm4 == now.second() || seconds_alarm5 == now.second() || all_seconds) {
              digitalWrite(LedPin, HIGH);
              future = now.unixtime() + alarm_duration; 
              Serial.println("------------");  
              Serial.println("ALARMA"); 
              Serial.println("------------");      
            }  
          }
        }
      }  
    }   
  }
}

if (now.unixtime() >= future.unixtime() && digitalRead(LedPin)){
digitalWrite(LedPin, LOW); 
Serial.println("------------");  
Serial.println("RESET ALARMA"); 
Serial.println("------------");
}

delay(1000); // La informaciÃ³n se actualiza cada 1 seg.
}

