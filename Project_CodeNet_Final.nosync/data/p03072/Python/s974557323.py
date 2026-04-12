N = int(input())
H_list = list(map(int,input().split()))
counter = 1
standard = H_list[0]
for i in range(1,N):
  if H_list[i]>=standard:
    counter +=1
    standard = H_list[i]

print(counter)