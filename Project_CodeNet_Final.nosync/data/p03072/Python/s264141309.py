N=int(input())
H_list = [int(i) for i in input().split()]
max_height=0
result=0
for height in H_list:
  if height>=max_height:
    result+=1
    max_height = height
print(result)