n = int(input())
test = list(map(int,input().split()))
counter = 0
    
for i in range(len(test)):
    test2 = test[:i+1]
    if max(test2) == test2[-1]:
        counter += 1
        
print(counter)