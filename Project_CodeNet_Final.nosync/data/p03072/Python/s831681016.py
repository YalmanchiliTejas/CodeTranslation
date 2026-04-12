num = list(map(int, input().split()))
heights = list(map(int, input().split()))
view = 0

for i, height in enumerate(heights):
    if i==0:
        view +=1
    else:
        if height >= max(heights[0:i]):
            view +=1
        
    
print (view)

 
