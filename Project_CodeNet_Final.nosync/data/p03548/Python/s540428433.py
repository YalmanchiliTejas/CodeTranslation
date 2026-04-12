
x=list(map(int,input().split()))

nu=(x[0]-x[2]) % (x[1]+x[2])
res=(x[0]-x[2]-nu) / (x[1]+x[2])
print(int(res))
    
    
