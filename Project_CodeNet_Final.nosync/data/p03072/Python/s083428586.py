# -*- coding: utf-8 -*-
n = int(input())
hotels = [int(hotel) for hotel in input().split()]

highest = hotels[0]
hasOceanView = 0
for hotel in hotels:
  if hotel >= highest:
    hasOceanView += 1
    highest = hotel

print(hasOceanView)
