def judgement(n, m):
    if n == m:
        return 'Yes'
    else:
        return 'No'

if __name__ == "__main__":
    n, m = input().split(' ')
    print(judgement(n, m))