n = raw_input()                                    

ar = []                                            
h = raw_input().split()                            

cnt = 0                                            
m = 0
for i in h:
    i = int(i)                                     
    if (i >= max(m, i)):
        cnt += 1                                   
        m = i

print cnt  