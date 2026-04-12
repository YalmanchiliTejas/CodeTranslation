p,q= input().split()
a,b =(int(p), int(q))
a_list = []
count_row = 0
b_h ='.'*b

for i in range(a):
    c = input()
    
    if c == b_h:
        count_row+=1
    else:
        a_list.append(c)

ans_list=[]
for i in range(b):
    count_clm = 0
    
    for j in range(a-count_row):
        if a_list[j][i] == '.':
            count_clm+=1
    
    
        if count_clm == (a-count_row):        
            ans_list.append(i)



for j in range(a-count_row):
    total=''
    for i in range(b):
        if i in ans_list:
            ds = 0
        else:
            total +=a_list[j][i]
            
    print(total)