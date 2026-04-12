N=int(input())
H_list=list(map(int, input().split()))
count=0
for i in range(len(H_list)):
  if i==0:
    min_H=H_list[i]
    count=count+1
    continue
  if H_list[i]>=min_H:
    count=count+1
    min_H=H_list[i]

print(count)
    
   
