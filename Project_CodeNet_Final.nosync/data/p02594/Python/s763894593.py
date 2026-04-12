def main(X):
    if X >= 30:
        return 'Yes'
    else:
        return 'No'

if __name__ == '__main__':
    X = int(input())
    ans = main(X)
    print(ans)

