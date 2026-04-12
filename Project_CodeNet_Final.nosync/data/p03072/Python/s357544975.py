n=int(input())
lst = list(map(int, input().split()))

ct = 1
for i in range(n-1):
  if max(lst[0:i+1]) <= lst[i+1]:
    ct+=1
    #print("ct =", ct)
print(ct)