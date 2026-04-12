#除くではなくて除かなくていい部分を選ぶ→各文字で考えず行・列単位で考える
h,w = list(map(int,input().split()))
a = [""] * h

for i in range(h):
    a[i] = input()
    
row = [False] * h
col = [False] * w

for i in range(h):
    for j in range(w):
        if a[i][j] == "#":
            row[i] = True
            col[j] = True
            
for i in range(h):
    if row[i]:
        for j in range(w):
            if col[j]:
                print(a[i][j],end="")
        print()