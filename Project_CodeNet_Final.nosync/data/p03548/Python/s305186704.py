def main():
    X, Y, Z = map(int, input().split())
    return (X-Z) // (Y+Z)
if __name__ == '__main__':
    print(main())
