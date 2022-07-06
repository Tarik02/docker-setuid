FROM alpine as builder

RUN apk add build-base

ADD src /src

RUN set -e \
  && gcc -static -static-libgcc -static-libstdc++ /src/main.c -Werror -o /docker-setuid \
  && chmod u+s /docker-setuid


FROM scratch

COPY --from=builder /docker-setuid /docker-setuid

CMD [ "/docker-setuid" ]
