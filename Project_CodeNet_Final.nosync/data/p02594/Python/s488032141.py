import sys
from os import path

if(path.exists('input.txt')):
    sys.stdin = open("input.txt","r")
    sys.stdout = open("output.txt","w")

n = int(input())
if(n>=30):
    print("Yes")
else:
    print("No")