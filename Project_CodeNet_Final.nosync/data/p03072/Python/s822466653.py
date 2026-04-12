n = int(input())
H = [int(i) for i in input().strip().split()]
 
border = 0
can_num = 0
for h in H:
  if h >= border:
    can_num += 1
    border = h
 
print(can_num)