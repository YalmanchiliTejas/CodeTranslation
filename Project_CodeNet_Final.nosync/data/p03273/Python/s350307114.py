h, w = map(int, input().split())
cnt = [0]*w
wRemove = 0
hRemove = 0
squares = []
hRemoveList = []
wRemoveList = []
for _ in range(h) :
        a = list(input())
        squares.append(a)
for i in range(h) :
        for j in range(w) :
                if squares[i][j] == '.' :
                        cnt[j] += 1
for i in range(w) :
        if cnt[i] == h :
                wRemove += 1
                wRemoveList.append(i)
wRemoveList.sort(reverse = True)
if not wRemoveList == [] :
        for i in range(h) :
                for j in wRemoveList :
                        del squares[i][j]
for i in range(h) :
        if squares[i] == ['.']*(w - wRemove) :
                hRemove += 1 
                hRemoveList.append(i)   
hRemoveList.sort(reverse = True)           
for i in hRemoveList :
        del squares[i]
for i in range(h-hRemove) :  
        print(''.join(squares[i])) 