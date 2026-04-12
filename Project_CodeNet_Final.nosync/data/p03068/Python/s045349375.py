import re
def main():
    N = int(input())
    S = input()
    K = int(input())
    nontarget = S[K - 1]
    S = S.replace(nontarget, '0')
    S = re.sub('\D', '*', S)
    S = S.replace('0', nontarget)
    print(S)
main()
