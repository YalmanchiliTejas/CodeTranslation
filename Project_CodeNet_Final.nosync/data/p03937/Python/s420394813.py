h,w = map(int,input().split())

cnh = 0
cnb = 0
for i in range(h):
    s = input()
    for j in range(w):
        if(s[j]=='#'):
            cnh +=1
        else:
            cnb+=1
            
ch = 1
if( cnh == h+w-1):
    ch = 1
else:
    ch = 0

    
if(ch==1):
    print("Possible")
else:
    print("Impossible")
    