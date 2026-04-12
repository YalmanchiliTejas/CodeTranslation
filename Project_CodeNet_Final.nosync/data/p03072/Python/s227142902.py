N = int(input())
acc_max = 0
cnt = 0
all_list = list(map(int, input().split()))

for x in all_list:
  if x >= acc_max:
    cnt += 1
    acc_max = x
    
print(cnt)
