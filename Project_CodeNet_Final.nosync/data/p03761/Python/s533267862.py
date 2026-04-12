N = int(input())
al = [chr(ord('a') + i) for i in range(26)]
out = dict(zip(al,[100]*26))
for i in range(N):
    S = list(input())
    tmp = dict(zip(al,[0]*26))
    for T in S:
        tmp[T] += 1
    for key in out.keys():
        out[key]=min(out[key],tmp[key])
outS = ""
for key in out.keys():
    outS += key*out[key]
print(outS)
