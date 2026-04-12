# coding: utf-8
import os, sys

S = str(input())
ans = len(set(S))

print("No") if ans == 1 else print("Yes")    
