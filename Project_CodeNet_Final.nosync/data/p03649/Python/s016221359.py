#coding=UTF-8

'''
27 0 0 0 0 0 0 ->(3)
6 3 3 3 3 3 3
'''

N=int(input())

mozir=input()
hyo=mozir.split(' ')
a=[int(mono) for mono in hyo]

ans=0
tgt=0
while True:
    dist=a[tgt]-(N-1)
    kai=dist//N + (1 if dist%N != 0 else 0)
    ans+=kai

    for idx in range(0,N,1):
        if idx != tgt:
            a[idx]+=kai
        else:
            a[idx]=a[idx]%N

    if tgt==N-1:
        turuturup=True
        for idx in range(0,N,1):
            if a[idx]>=N:
                turuturup=False
                break

        if turuturup:
            break
    tgt=(tgt+1)%N

print(ans)
