#coding;:utf-8

N=input()
s=raw_input()

def f(i):
    return i%len(s)

def ok(buf):
    for i in range(len(buf)):
        if buf[i]:
            if s[i] == "o":
                if buf[f(i-1)] != buf[f(i+1)]: return False
            else:
                if buf[f(i-1)] == buf[f(i+1)]: return False
        else:
            if s[i] == "o":
                if buf[f(i-1)] == buf[f(i+1)]: return False
            else:
                if buf[f(i-1)] != buf[f(i+1)]: return False            
    return True

OK=[]
# True: sheep; False: wolf
for b in range(1<<3):
    buf=[None] * N
    if b&0b001:buf[0]=True
    else:buf[0]=False
    if (b&0b010)>>1:buf[1]=True
    else:buf[1]=False
    if (b&0b100)>>2:buf[-1]=True
    else:buf[-1]=False

    for i in range(2, N-1):
        if s[i-1] == "o":
            if buf[i-1]:
                buf[i]=buf[i-2]
            else:
                buf[i]=not buf[i-2]
        else:
            if buf[i-1]:
                buf[i]=not buf[i-2]
            else:
                buf[i]=buf[i-2]
    if ok(buf):
        OK.append("".join("S" if b else "W" for b in buf))
if len(OK)==0:
    print(-1)
else:
    print(OK[0])




    
