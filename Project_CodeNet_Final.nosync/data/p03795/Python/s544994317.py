n = int(input())
y_count = 0
x = 800*n

for i in range(1,n+1):
    if i%15==0:
        y_count+=1
    
print(x-y_count*200)