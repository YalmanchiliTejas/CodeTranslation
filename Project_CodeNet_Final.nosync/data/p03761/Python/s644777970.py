N = int(input())

al = [chr(ord('a') + i) for i in range(26)]
out = dict(zip(al,[100]*26))
# print(out)

for i in range(N):
    S = list(input())
    dam = dict(zip(al,[0]*26))
    for T in S:
        dam[T] += 1   #辞書Tに+1
    for key in out.keys():
        out[key] = min(out[key], dam[key])
    # print(dam)
outS = ""
for key in out.keys():
    # print(key)
    outS += key*out[key]
print(outS)
