X, Y, Z = map(int, input().split())
mylist=[]
for i in range(X):
    if (Y*i)+(Z*(i+1)) <= X:
        mylist.append(1)
    else:
        pass
print(len(mylist)-1)