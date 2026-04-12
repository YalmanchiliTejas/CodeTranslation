from sys import stdin


#1行に１つの数字
n = int(stdin.readline().rstrip())

if n == 3 or n == 5 or n == 7:
    print("YES")
else:
    print("NO")