def read():
    S = str(input().strip())
    return S,

def solve(S):
    if S == "AAA" or S == "BBB":
        return "No"
    return "Yes"

if __name__ == '__main__':
    inputs = read()
    print("{}".format(solve(*inputs)))
