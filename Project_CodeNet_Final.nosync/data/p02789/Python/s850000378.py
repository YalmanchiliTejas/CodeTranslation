import logging

logging.basicConfig(level=logging.INFO, format="%(message)s")
#logging.disable(logging.CRITICAL)

def main():
    N, M = map(int, input().split())
    logging.info("Hello!")

    if N == M:
        print("Yes")
    else:
        print("No")
        
if __name__ == "__main__":
    main()
