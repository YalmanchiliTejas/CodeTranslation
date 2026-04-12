h,w = map(int,input().split())
X = []

for i in range(h):
    x = input()
    
    if x.count(".") != w:
        x = list(x)
        X.append(x)
        
h = len(X)

for i in range(w):
    wrong = 0
    for j in range(h):
        if X[j][i] == ".":
            wrong += 1
            
        if wrong == h:
            for k in range(h):
                X[k][i] = "*"
                
for i in range(h):
    print(("".join(X[i])).replace("*",""))