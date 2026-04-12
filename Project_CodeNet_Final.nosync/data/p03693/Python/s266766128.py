#x, y = map(int,input().split())
ls = list(map(int,input().split()))
#r = int(input())
#s = input()
#x, y = input().split()

num = int(ls[0]) * 100 + int(ls[1]) * 10 + int(ls[2])
if num%4 == 0:
  print("YES")
else:
  print("NO")