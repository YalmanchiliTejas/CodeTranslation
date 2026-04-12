
input_line =input()
input_line = input_line.rstrip().split(" ")

a = int(input_line[0])
b = int(input_line[1])
c = int(input_line[2])
x = int(input_line[3])
y = int(input_line[4])

list1=[]
for i in range(max(x,y)+1):
    if x-i<=0 and y-i<=0:
        cost = 2*c*i
        list1.append(cost)
        i +=1
        
    elif x-i<=0:
        cost = b*(y-i)+2*c*i
        list1.append(cost)
        i +=1
        
    elif y-i<=0:
        cost = a*(x-i)+2*c*i
        list1.append(cost)
        i +=1
    
    else:
        cost = a*(x-i)+b*(y-i)+2*c*i
        list1.append(cost)
        i +=1
    

print(min(list1))