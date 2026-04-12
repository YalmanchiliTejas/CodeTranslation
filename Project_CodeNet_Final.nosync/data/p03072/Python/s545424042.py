n = int(input())
l = [int(i) for i in input().split()]
flag = 0
for i in range(n):
  l_h = l[:i+1]
  if l_h[i] == max(l_h):
    flag +=1
print(flag)
  