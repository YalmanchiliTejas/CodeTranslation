import collections

N = 3
SRR = [
    "cbaa",
    "daacc",
    "acacac"
]

N = 3
SRR = [
    "a",
    "aa",
    "b",
]

N = 3
SRR = [
    "addc",
    "dda",
    "da",
]

N = int(input())
SRR = []

for i in range(N):
    SRR.append(input())

def calculate(n, srr):
    # res = {"a": 0, "b": 0, "c": 0, "d": 0, "e": 0, "f": 0, "g": 0, "h": 0, "i": 0, "j": 0, "k": 0, "l": 0, "m": 0,
    #        "n": 0, "o": 0, "p": 0, "q": 0, "r": 0, "s": 0, "t": 0, "u": 0, "v": 0, "w": 0, "x": 0, "y": 0, "z": 0}

    # for l in srr[0]:
    #     res.add(l)

    res = collections.Counter(srr[0])


    for sr in srr:
        sr = collections.Counter(sr)
        res = sr & res

    # print(res)
    result = ""
    for key in sorted(res.keys()):
        result += key * res.get(key)

    print(result)

calculate(N, SRR)
