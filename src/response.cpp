#include "response.h"

lrrp::response::response() {
    body = json::object();
}

lrrp::response::response(const std::string& raw) {
    body = json::parse(raw);
}

void lrrp::response::set_payload(const json& payload) {
    body["payload"] = payload;
}

void lrrp::response::set_status(status_type status) {
    body["status"] = status;
}

json lrrp::response::jsonify() const {
    return body;
}

std::string lrrp::response::stringify() const {
    return body.dump();
}

lrrp::response lrrp::response::from_string(const std::string& raw) {
    return response(raw);
}

json lrrp::response::get_payload() {
    return body["payload"];
}
