countH = 0
N = int(input())
H_lists = map(int,input().split(" "))
max_tmp=0
for Hi in H_lists:
    if Hi>=max_tmp:
        countH+=1
        max_tmp=Hi        
print(countH)    