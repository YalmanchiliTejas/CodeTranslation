 # -*- coding: utf-8 -*-

[X, Y, Z] = [int(i) for i in input().split()]

personal_width = Y + Z
chair_width = X - Z

number = chair_width // personal_width
amari = X % personal_width

if amari >= X:
    number += 1

print(number)