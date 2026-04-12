N = int(input())

s = input()

ans_first = ["SS", "SW", "WS", "WW"]

cand_oo = ["SSSS", "SWWS", "WWSW", "WSWW"]
cand_ox = ["SSSW", "SWWW", "WWSS", "SSWS"]
cand_xo = ["WSSS", "WWWS", "SWSW", "SSWW"]
cand_xx = ["WSSW", "WWWW", "SWSS", "WSWS"]

answered = False

for a in ans_first:
    if answered == True:
        break
        
        
    for i in range(1, N-1):
        if (s[i] == "o" and a[i] == "S") or (s[i] == "x" and a[i] == "W"):
            a = a + a[i-1]
            
        elif (s[i] == "o" and a[i] == "W") or (s[i] == "x" and a[i] == "S") :
            if a[i-1] == "S":
                a = a + "W"
            else:
                a = a + "S"
            
    if s[-1] + s[0] == "oo": 
        for can in cand_oo:
            if can == a[-2:] + a[:2]:
                print(a)
                answered = True
                break
                
    elif s[-1] + s[0] == "ox": 
        for can in cand_ox:
            if can == a[-2:] + a[:2]:
                print(a)
                answered = True
                break
    
    elif s[-1] + s[0] == "xo": 
        for can in cand_xo:
            if can == a[-2:] + a[:2]:
                print(a)
                answered = True
                break
    
    elif s[-1] + s[0] == "xx": 
        for can in cand_xx:
            if can == a[-2:] + a[:2]:
                print(a)
                answered = True
                break
                
if answered == False:
    print(-1)