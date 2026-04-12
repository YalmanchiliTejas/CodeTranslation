N = int(input())
Hs= list(map(int, input().split()))


h1 = Hs.pop(0)
hmax = h1
hotel_cnt = 1

for i,h in enumerate(Hs):
    if hmax <= h:
        hotel_cnt += 1
        hmax = h

print(hotel_cnt)                    
