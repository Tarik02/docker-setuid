FROM ubuntu

RUN apt-get -y update
RUN apt-get -y install nginx

COPY --from=tarik02/setuid /docker-setuid /docker-setuid

COPY setup.sh /setup.sh

CMD [ "/docker-setuid", "0", "/usr/bin/bash", "/setup.sh" ]
