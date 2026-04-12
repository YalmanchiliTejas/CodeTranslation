a=int(input())
n = list(map(int, input().split()))
max=0
count=0
for i in range(a):
  if n[i]>=max:
    count+=1
    max=n[i]
print(count)